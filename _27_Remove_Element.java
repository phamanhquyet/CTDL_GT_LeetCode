public class _27_Remove_Element {

    public static int removeElement(int[] a, int val) {
        int n = a.length;
        for (int i = 0; i < n;) {
            if (a[i] == val) {
                for (int j = i; j <= n - 2; j++) {
                    a[j] = a[j + 1];
                }
                n--;
            } else {
                i++;
            }
        }
        return n;
    }

    public static void main(String[] args) {
        int[] a = { 3, 2, 2, 3 };
        System.out.println(removeElement(a, 2));
        System.out.println("done");
    }
}
