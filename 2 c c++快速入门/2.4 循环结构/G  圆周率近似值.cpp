/*   pi/4≈1-1/3+1/5-1/7+......
计算到某一项的绝对值小于10^6
*/
#include<stdio.h>
#include<math.h>

int main() {
    double Pi = 0, i, sum = 0.0, n;
    for (i = 1.0;; i++) {
        n = 1 / (2 * i - 1);
        if (n <= pow(10, -6)) {
            break;
        }
        sum += pow(-1, i + 1) * n;
        Pi = sum * 4.0;
    }
    printf("PI=%10.8lf\n", Pi);

    return 0;
}