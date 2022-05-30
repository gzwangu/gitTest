 public static List<List<Integer>> allPathsSourceTarget(int[][] graph) {
 //判断节点是否被访问
  boolean m[][] = new boolean[graph.length][];
        Stack<Integer> stack = new Stack<Integer>();
        stack.add(0);
        List<List<Integer>> list1 = new LinkedList<List<Integer>>();
//初始化该布尔数组
  for(int i=0;i<graph.length;i++){
   m[i] = new boolean[graph[i].length];
   for(int j=0;j<graph[i].length;j++)
    m[i][j] = false;
  }
  //只要栈不为空
        while(!stack.isEmpty()){
        //查看当前节点
         int current = stack.peek();
         //判断是否为目标节点
         if(current==graph.length-1){
          list1.add(new LinkedList<Integer>(stack));
          stack.pop();
         }
         else{
          int p = 0;
          for(int i=0;i<graph[current].length;i++){
          //判断此邻接点是否已经被访问过
           if(m[current][i] == false){
            stack.push(graph[current][i]);
            System.out.println(graph[current][i]);
            m[current][i] = true;
            p = 1;
            break;
           }
          }
          if(p==0){
          //如果所有邻接点已经被访问过了或者没有邻接点，重置布尔数组，并出栈
           for(int i=0;i<graph[current].length;i++){
            m[current][i] =false;
           }
           stack.pop();
          }
         }
        }
        return list1;
    }