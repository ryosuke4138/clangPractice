/*
 * 多重三角形
 * point.txtを読み込み、3つの三角形から構成される三角形を探し,  
 * さらにその三角形から構成される三角形を探すプログラム
 * 中に点のない三角形を1重とした時に 4重となる三角形を探し,  その頂点座標を出力
 */

#include <stdio.h>
#include <stdbool.h>
#define N 17

/* 座標の構造体 */
typedef struct {
  double x;
  double y;
} XY;

/* 座標用構造体からベクトル算出 */
XY mk_vector(XY p0, XY p1){
	XY v;
	v.x = p1.x - p0.x;
	v.y = p1.y - p0.y;
	return v;
}

/* ベクトルの外積 */
double outer_cros(XY v0, XY v1){
	return (v0.x * v1.y) - (v0.y * v1.x);
}

/* 内外確認 */
bool is_in_triangle(double oc0, double oc1, double oc2){
	if((oc0 > 0 && oc1 > 0 && oc2 > 0) ||  (oc0 < 0 && oc1 < 0 && oc2 < 0)) {
    	return true;
	}else{
    	return false;
	}
}

/* 組み合わせ */
int buffer[N] = {0};
int num=0;

void print_combination(int n, int *A, int num)
{
  for (int i = 0; i < n; i++)
    *(A+i+n*num) = buffer[i];
}

void comb_sub(int n, int r, int m, int *A)
{
  if (r == 0)
    print_combination(m, A, num++);
  else if (n == r) {
    for (int i = r; i > 0; i--)
      buffer[m++] = i;
    print_combination(m, A, num++);
  } else {
    comb_sub(n - 1, r, m, A);
    buffer[m] = n;
    comb_sub(n - 1, r - 1, m + 1, A);
  }
}

void combinations(int n, int r, int *A){
  if (r > 0 && r <= N) comb_sub(n, r, 0, A);
}


int main(void){
  FILE *fp;
  /* 座標 */
  XY p[N];
  /* ベクトル */
  XY a, b, c, d, v_ab, v_bc, v_ca, v_ad, v_bd, v_cd;
  
  /* ファイルの読み込み・座標代入 */
  fp = fopen("point.txt", "r"); 
  if(fp ==NULL)
    printf("\aファイル\"point.txt\"をオープンできませんでした。\n");
  else {
    printf("\aファイル\"point.txt\"を読み込みました。\n"); 
    for(int i=0; fscanf(fp, "%lf%lf", &p[i].x, &p[i].y) == 2; i++){
      printf("%lf %lf\n", p[i].x, p[i].y);
    }
  }

  /* 組み合わせ */
  int A[680][3] = {0};
  combinations(N, 3, *A);
  int ans[680] = {0};
  for(int i=0; i<680; i++){
    int cnt=0; // 三角形の中の点の数
    a.x = p[A[i][0]].x; a.y = p[A[i][0]].y; 
    b.x = p[A[i][1]].x; b.y = p[A[i][1]].y;
    c.x = p[A[i][2]].x; c.y = p[A[i][2]].y;
  
    /* 内外確認 */
    for(int j=0; j<17; j++){
      d.x = p[j].x; d.y = p[j].y;
      v_ab = mk_vector(a, b);
	    v_bc = mk_vector(b, c);
	    v_ca = mk_vector(c, a);
	    v_ad = mk_vector(a, d);
	    v_bd = mk_vector(b, d);
	    v_cd = mk_vector(c, d);

      if(is_in_triangle(outer_cros(v_ab, v_ad), outer_cros(v_bc, v_bd), outer_cros(v_ca, v_cd))) cnt++;
    }

    if(cnt==4){ 
      ans[i] = 1;
    }else 
      ans[i] = 0;
  }

  for(int i=0; i<570; i++){
    if(ans[i] == 0) continue;
    int k=0;
    while(k++<3){
      printf("(%.2f, %.2f),", p[A[i][k]].x, p[A[i][k]].y);
    }
    printf("\n");
    int r=0;
    if(++r>14)break;
  }

  fclose(fp);
  return 0;
}
