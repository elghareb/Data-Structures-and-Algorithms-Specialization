package DataStructures;

public class UnionFind {
    int[] parent, rank, setSize;
    int numSets;

    //rank = height
    public UnionFind(int N) {
        parent = new int[numSets = N];
        rank = new int[N];
        setSize = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            setSize[i] = 1;
        }
    }

    public int findSet(int i) {
        //path compression
        return parent[i] == i ? i :( parent[i]=findSet(parent[i]));
    }

    public boolean isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    public int numDisjointSets() {
        return numSets;
    }

    public int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }

    public void unionSet(int i, int j) {
        if (isSameSet(i, j))
            return;
        numSets--;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
            parent[y] = x;
            setSize[x] += setSize[y];
        } else {
            parent[x] = y;
            setSize[y] += setSize[x];
            if (rank[x] == rank[y]) rank[y]++;
        }

    }
}
