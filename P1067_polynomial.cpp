#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
    int t, a;
    char* exp = new char[105];
    char* asw = new char[100000000];
    scanf("%d", &t); //项数

    for (int i = t; i >= 0; i--) {
        scanf("%d", &a);
        //拆成第一项、前面的项和最后一项
        if (i == t) { //第一项
            if (a == -1) {
                sprintf(exp, "-");
                strcat(asw, exp);
            } else if (a != 1) {
                sprintf(exp, "%d", a);
                strcat(asw, exp);
            }
            //2. 添加x项
            sprintf(exp, "x^%d", i);
            strcat(asw, exp);

        } else if (i != 0) { //中间的项
            //1. 添加系数上去
            if (a == 1) {
                sprintf(exp, "+");
                strcat(asw, exp);
            } else if (a == -1) {
                sprintf(exp, "-");
                strcat(asw, exp);
            } else if (a > 0) {
                sprintf(exp, "+%d", a);
                strcat(asw, exp);
            } else if (a < 0) {
                sprintf(exp, "%d", a);
                strcat(asw, exp);
            }
            //2. 添加x项
            if (a != 0 && i != 1) {
                sprintf(exp, "x^%d", i);
                strcat(asw, exp);
            } else if (a != 0 && i == 1) {
                strcat(asw, "x");
            }
        } else { //最后一项
            //只用添加系数
            if (a > 0) {
                sprintf(exp, "+%d", a);
                strcat(asw, exp);
            } else if (a < 0) {
                sprintf(exp, "%d", a);
                strcat(asw, exp);
            }
        }
    }

    printf("%s", asw);
    return 0;
}
