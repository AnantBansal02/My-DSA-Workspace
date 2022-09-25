import java.util.Random;
import java.util.Scanner;

public class Ques {
    static void Merge(int arr[], int start, int end, int part) {
        int n1 = part - start + 1;
        int n2 = end - part;
        int a[] = new int[n1];
        int b[] = new int[n2];
        for (int i = 0; i < n1; i++) {
            a[i] = arr[start + i];
        }
        for (int i = 0; i < n2; i++) {
            b[i] = arr[part + 1 + i];
        }
        int i = 0, j = 0;
        int k = start;
        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                arr[k] = a[i];
                k++;
                i++;
            } else {
                arr[k] = b[j];
                k++;
                j++;
            }
        }
        while (i < n1) {
            arr[k] = a[i];
            k++;
            i++;
        }
        while (j < n2) {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    static void MergeSort(int arr[], int start, int end) {
        if (start >= end) {
            return;
        }
        int part = start + ((end - start) / 3);
        MergeSort(arr, start, part);
        MergeSort(arr, part + 1, end);
        Merge(arr, start, end, part);
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the Number of random Elements to be Sorted : ");
            int n = sc.nextInt();
            System.out.print("Enter the Range to be given to these numbers : ");
            int range = sc.nextInt();
            int arr[] = new int[n];
            Random rn = new Random();
            for (int i = 0; i < n; i++) {
                arr[i] = rn.nextInt(range);
            }
            MergeSort(arr, 0, n - 1);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
            }
        }
    }
}