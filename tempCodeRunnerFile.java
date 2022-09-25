public class StoogeSort {
    static int count = 0;

    static void fun(int arr[], int l, int h) {
        count++;
        if (arr[l] > arr[h]) {
            int temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;
        }
        if (h - l == 2) {
            if (arr[l + 1] > arr[h]) {
                int temp = arr[l + 1];
                arr[l + 1] = arr[h];
                arr[h] = temp;
            }
            return;
        }
        int first, second;
        first = ((h - l) / 3) * 2 + l;
        second = (h - l) / 3 + l;
        fun(arr, l, first);
        fun(arr, second, h);
        fun(arr, l, first);
    }

    public static void main(String args[]) {
        int arr[] = { 2, 8, 10, 4, 1, 3 };
        fun(arr, 0, 4);
        for (int i = 0; i < 5; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        System.out.println("Recursive Calls : " + count);
    }
}
