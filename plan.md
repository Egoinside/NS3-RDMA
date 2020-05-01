# Schedule for RDMA

Reference repo: [ZHU Yibo DCQCN](https://github.com/bobzhuyb/ns3-rdma), [MIAO Rui HPCC](https://github.com/alibaba-edu/High-Precision-Congestion-Control). 
ns-3 code style check script: `utils/check-style.py`.







## Discussion notes

### 20200424 launching

1. PFC (header)的实现，严格参照文档还是自定义tag，实现思路类似即可？

   A：出于方便和可读性，自定义tag，依照文档思路即可。

2. PFC module 抽象写到哪？

   A：L2层，自定义相关的switch node。

3. 关于 node type，DCQCN 除原本的node外写了一个 RDMA 专用的 switch node。这样最终跑 RDMA 或者 TCP 需要写两个 main 函数，而且两种流不能一起跑。参考 RDMA 相关的几篇paper，可能没有同时跑 DCQCN 和 DCTCP 的需求，所以我们也选择另写一个 switch node。

4. separate task:

   1. switch node
   2. reliable UDP (app/udp-echo-client)
   3. RDMA (net-device part)

5. 对后续 RDMA 上 load-balance 工作友好比较难。

6. 先加文件名；记得参考 ns3 在文件里写文件描述、函数描述的注释。



