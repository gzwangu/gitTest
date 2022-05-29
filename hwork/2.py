#k-means伪代码
import numpy as np
import copy
#计算欧氏距离
def get_distance(X,Y):
    return np.sum((X-Y)**2)**0.5
def calc_mean(X): #计算中心点，每一维取均值
    l=len(X[0])
    list_mean=[]
    for i in range(l):
        s=0
        for j in X:
            s+=j[i]
        m=s/len(X)
        list_mean.append(m)
    return list_mean
 
def k_means(x_train,k,max_iter):
    num_iter = 0
    #初始簇中心
    cluster_center = x_train[:k]
    pre_cluster_center = copy.deep_copy(cluster_center) #上一次的簇中心点
    #开始迭代
    while num_iter<max_iter:
        #临时变量
        clusters_data={} #字典{簇下标：坐标}
        for i in x_train:
            cluster_dists=[]
            for index,cluster in enumerate(cluster_center):
                distance=get_distance(i,cluster)
                cluster_dists.append((index,distance)) #每个样本到中心点的距离
            
            cluster_dists.sort(key=lambda x:x[1]) #升序
            min_index,min_dist=cluster_dists[0] #取距离最近
            
            if min_index not in clusters_data:
                clusters_data[min_index]=[]
            clusters_data[min_index].append(i) #数据添加到临时变量中
            
        #更新簇中心点
        for index in clusters_data:
            cluster_center[index]=calc_mean(clusters_data[index])
        if pre_cluster_center == cluster_center:
            break   #如果簇中心点不再变化，那么结束
        else:
            pre_cluster_center = copy.deep_copy(cluster_center) #拷贝一下
    return cluster_center #返回最终的簇中心点