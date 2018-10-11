package DataStructures;

public class Heap {
    private int H[];
    private int maxSize;
    private int size;

    public int leftChild(int i) {
        return 2 * i + 1;
    }

    public int rightChild(int i) {
        return 2 * i + 2;
    }

    public int partent(int i) {
        return (i - 1) / 2;
    }

    public void swap(int i, int j) {
        int tmp = H[i];
        H[i] = H[j];
        H[j] = tmp;
    }

    public Heap(int maxSize) {
        H = new int[maxSize];
        size = 0;
        this.maxSize = maxSize;
    }

    public void siftUp(int i) {
        while (i > 0 && H[partent(i)] < H[i]) {
            swap(i, partent(i));
            i = partent(i);
        }
    }

    public void siftDown(int i) {
        int mxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);
        if (l < size && H[l] > H[mxIndex]) {
            mxIndex = l;
        }
        if (r < size && H[r] > H[mxIndex]) {
            mxIndex = r;
        }
        if (i != mxIndex) {
            swap(i, mxIndex);
            siftDown(mxIndex);
        }
    }

    public int insert(int p) {
        if (size == maxSize) {
            return -1;
        }
        H[size] = p;
        siftUp(size);
        size++;
        return 1;
    }

    public int extractMax() {
        int result = H[0];

        H[0] = H[--size];
        H[size]= 0;
        siftDown(0);
        return result;
    }

    public void remove(int i) {
        H[i] = 1000000;
        siftUp(i);
        extractMax();
    }

    public void changePriority(int i, int p) {
        int oldp = H[i];
        H[i] = p;
        if (p > oldp)
            siftUp(i);
        else
            siftDown(i);
    }

    public void printHeap() {
        int x = 0;
        for (int i = 1; i < 8; i *= 2) {
            for (int j = 0; j < i; j++) {

                System.out.print(H[x++] + " ");
            }
            System.out.println();
        }
    }
}

//        0
//     1     2
//    3 4   5 6