public class Demo {
    public void Perm(int list[], int k, int m) {
        if (k == m) {
            for (int i = 0; i <= m; i++)
                System.out.print(list[i]);
            System.out.println();
        } else {
            for (int i = k; i <= m; i++) {
                // �ӹ̶��������һ�����ν���
                Swap(list, k, i);
                Perm(list, k + 1, m);
                // ����ݹ����֮����Ҫ��������
                Swap(list, k, i);
            }
        }
        
    }
    public void Swap(int[] list, int i, int j) {
        int t = list[i];
        list[i] = list[j];
        list[j] = t;
    }
    public static void main(String[] args) {
        Demo d = new Demo();
        int[] arr = {1,2,3,4};
        d.Perm(arr, 0, 3);
    }
}