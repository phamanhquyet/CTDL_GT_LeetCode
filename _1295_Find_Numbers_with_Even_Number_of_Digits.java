public class _1295_Find_Numbers_with_Even_Number_of_Digits {
    public static int findNumbers(int[] nums) {
        int count = 0;
        for (int i : nums) {
            int numberOfDigits = calculateNumberOfDigits(i);
            if (numberOfDigits % 2 == 0) {
                count++;
            }
        }
        return count;
    }

    private static int calculateNumberOfDigits(int i) {
        int count = 0;
        int result = i;
        while (result != 0) {
            result = i / 10;
            i = result;
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        int[] nums = { 1444, 22, 3333, 4444 };
        System.out.println(findNumbers(nums));
    }
}