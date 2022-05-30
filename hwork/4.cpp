// Bellman–Ford算法
void bellmanford(){
    for(int i=0;i<n;i++){
        dist[i]=inf; //将起点a到各个顶点v的距离dist(a->v)赋值为inf
    }
    dist[s]=0; // dist(a->a)赋值为0
    for(int i=0;i<n-1;i++){ //对所有的边进行松弛操作
        for(int j=0;j<n;j++){
            if(dist[j]==inf){
                continue;
            }
            for(int k=head[j];k!=-1;k=edges[k].next){
                // 判断(dist(a) +weight(ab)) < dist(b)
                if(edges[k].w!=inf&&dist[edges[k].to]>dist[j]+edges[k].w){
                    //更新b点的总花费为(dist(a) +weight(ab))
                    dist[edges[k].to]=dist[j]+edges[k].w;
                }
            }
        }
    }
}