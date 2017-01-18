#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;

ll V,E,K;
vector<pair<ll, ll>> edge[801];

void dijkestra(ll startNode, ll check[], ll path[]){
    priority_queue<pair<ll, ll>> qu;
    qu.push(make_pair(startNode, 0));
    check[startNode] = 0;

    while (!qu.empty()) {
        ll node = qu.top().first;
        ll cost = qu.top().second;
        qu.pop();

        if (check[node] < cost)
            continue;

        for (ll i = 0 ; i < edge[node].size(); i++) {
            ll next_node = edge[node][i].first;
            ll next_cost = edge[node][i].second;

            if (check[next_node] > next_cost + cost) {
                path[next_node] = node;
                qu.push(make_pair(next_node, next_cost + cost));
                check[next_node] = next_cost + cost;
            }
        }
    }
}

int main() {
    const ll INF = 1600000000;
    scanf("%lld %lld", &V, &E);
    ll path_from_start[V], path_from_n1[V], path_from_n2[V];
    ll check_from_start[V], check_from_n1[V], check_from_n2[V];

    for (int i = 1 ; i <= E; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }

    for (ll i = 1; i <= V; i++) {
        path_from_start[i] = i;
        path_from_n1[i] = i;
        path_from_n2[i] = i;
    }

    ll n1, n2;
    scanf("%lld %lld", &n1, &n2);

    fill(&check_from_start[0], &check_from_start[V] + 1, INF);
    fill(&check_from_n1[0], &check_from_n1[V] + 1, INF);
    fill(&check_from_n2[0], &check_from_n2[V] + 1, INF);

    dijkestra(1, check_from_start, path_from_start);
    dijkestra(n1, check_from_n1, path_from_n1);
    dijkestra(n2, check_from_n2, path_from_n2);

    ll from_start_to_n1 = check_from_start[n1];
    ll from_n1_to_n2 = check_from_n1[n2];
    ll from_n2_to_end = check_from_n2[V];
    ll sum1 = from_start_to_n1 + from_n1_to_n2 + from_n2_to_end;
//    printf("from_start_to_n1 : %lld     from_n1_to_n2 : %lld    from_n2_to_end : %lld   sum1 : %lld\n", from_start_to_n1, from_n1_to_n2, from_n2_to_end, sum1);
//    for (int i = 1; i <= V; i++) {
//        cout << check_from_n1[i] << endl;
//    }


    ll from_start_to_n2 = check_from_start[n2];
    ll from_n2_to_n1 = check_from_n2[n1];
    ll from_n1_to_end = check_from_n1[V];
    ll sum2 = from_start_to_n2 + from_n2_to_n1 + from_n1_to_end;
//    printf("from_start_to_n2 : %lld     from_n2_to_n1 : %lld    from_n1_to_end : %lld   sum2 : %lld\n", from_start_to_n2, from_n2_to_n1, from_n1_to_end, sum2);
    ll result = min(sum1, sum2);
    if (result >= INF) {
        printf("-1\n");
    }else{
        printf("%lld\n", min(sum1, sum2));
    }


    return 0;
}
