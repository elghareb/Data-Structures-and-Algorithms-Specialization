//void dijkstra1(int s, int d) {
//
//	// node {cost or distance,node}
//	for (int i = 1; i <= n; i++)
//		dist[i] = OO;
//	dist[s] = 0;
//
//	while (true) {
//		int val = OO;
//		int parent = -1;
//		for (int i = 0; i < n; ++i) {
//			//get node with min cost and not visited
//			if (!vis[i] && dist[i] < val)
//				val = dist[i], parent = i;
//		}
//		if (parent == -1 || parent == d)
//			break;
//		vis[parent] = 1;
//
//		for (auto child : adj[parent]) {
//			if (dist[parent] + child.second < dist[child.first]) {
//				dist[child.first] = dist[parent] + child.second;
//				prev[child.first] = parent;
//			}
//		}
//
//	}
//
//}
//int dijkstra2(int n, int s, int d) {
//	priority_queue<pair<int, int>> q;
//	for (int i = 0; i < n; i++)
//		dist[i] = OO;
//	dist[s] = 0;
//
//	q.push( { 0, s });
//	while (!q.empty()) {
//		//choose node that minimum cost and not visited
//		int parent = q.top().second;
//		q.pop();
//		if (vis[parent])
//			continue;
//		vis[parent] = 1;
//
//		for (auto child : adj[parent]) {
//			if (dist[parent] + child.second < dist[child.first]) {
//				dist[child.first] = dist[parent] + child.second;
//				q.push( { -dist[child.first], child.first });
//			}
//		}
//	}
//	return dist[d] != OO ? dist[d] : -1;
//}