#include <stdio.h>

/*�� ���-1*/
void starprint() {
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++)
            printf("*");
        printf("\n");
    }
}
/*Hello World*/
void helloworld() {
    printf("Hello World!");
}
/*������*/
void gugu() {
    int n;
    scanf("%d", &n);
    for (int i=1;i<=9;i++)
        printf("%d * %d = %d\n", n, i, n*i);
}
/*��Ģ����*/
void fourop() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
    printf("%d\n", a-b);
    printf("%d\n", a*b);
    printf("%d\n", a/b);
    printf("%d\n", a%b);
}


int main() {
    starprint();
    helloworld();
    gugu();
    fourop();

    return 0;
}