#include <stdio.h>
#include <math.h>

void inputArray(double arr[], int size) {
    printf("Введіть %d елементів для масиву:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Елемент %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

void processArray(double arr[], int size, double* res1, double* res2, double* res3, char type) {
    double s = 0.0;
    for (int i = 0; i < size; i++) {
        s += arr[i];
    }

    if (type == 'N') {
        double sum_val_sin_val = 0.0;
        for (int i = 0; i < size; i++) {
            sum_val_sin_val += arr[i] * sin(arr[i]);
        }
        *res1 = s * sum_val_sin_val;

        double prod_val_sin_val = 1.0;
        for (int i = 0; i < size; i++) {
            prod_val_sin_val *= arr[i] * sin(arr[i]);
        }
        *res2 = prod_val_sin_val;

        double sum_val_cos_val = 0.0;
        for (int i = 0; i < size; i++) {
            sum_val_cos_val += arr[i] * cos(arr[i]);
        }
        *res3 = s * sum_val_cos_val;
    } else if (type == 'D') {
        double sum_val_tan_val = 0.0;
        for (int i = 0; i < size; i++) {
            sum_val_tan_val += arr[i] * tan(arr[i]);
        }
        *res1 = s * sum_val_tan_val;

        double prod_val_cos_val = 1.0;
        for (int i = 0; i < size; i++) {
            prod_val_cos_val *= arr[i] * cos(arr[i]);
        }
        *res2 = prod_val_cos_val;

        double sum_val_sin_val_denom = 0.0;
        for (int i = 0; i < size; i++) {
            sum_val_sin_val_denom += arr[i] * sin(arr[i]);
        }
        *res3 = s * sum_val_sin_val_denom;
    }
}

int main() {
    int n, m;

    printf("Введіть кількість елементів для масиву a (n): ");
    scanf("%d", &n);
    double a[n];
    inputArray(a, n);

    printf("Введіть кількість елементів для масиву b (m): ");
    scanf("%d", &m);
    double b[m];
    inputArray(b, m);

    double val_A, val_B, val_C;
    double val_D, val_E, val_F;

    processArray(a, n, &val_A, &val_B, &val_C, 'N');
    processArray(b, m, &val_D, &val_E, &val_F, 'D');

    printf("\nОбчислені значення:\n");
    printf("A = %lf\n", val_A);
    printf("B = %lf\n", val_B);
    printf("C = %lf\n", val_C);
    printf("D = %lf\n", val_D);
    printf("E = %lf\n", val_E);
    printf("F = %lf\n", val_F);

    double numerator = val_A * tan(val_B) + val_C;
    double denominator = val_D * sin(val_E) + val_F;
    
    if (denominator == 0) {
        printf("\nПомилка: Знаменник дорівнює нулю. Неможливо обчислити mu.\n");
    } else {
        double mu = numerator / denominator;
        printf("\nРезультат mu = %lf\n", mu);
    }

    return 0;
}