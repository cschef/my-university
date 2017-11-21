# 进程互斥与同步算法

## 生产者 - 消费者问题

生产者和消费者共用 n 个缓冲区，通过信号量 mutex 实现诸进程对缓冲池的互斥访问，信号量 full 和 empty 用来实现缓冲区的状态同步。

```cpp
int in = 0, out = 0;
item buffer[n];
semaphore mutex = 1;
semaphore empty = n; //空缓冲区数量
semaphore full = 0;  //满缓冲区数量

void producer() {
    while(true) {
        //product an item nextp;
        
        wait(empty);

        wait(mutex);
        buffer[in] = nextp;
        in = (in+1)%n;
        signal(mutex);

        signal(full);
    }
}

void consumer() {
    while(true) {
        wait (full);

        wait(mutex);
        nextc = buffer[out];
        out = (out+1)%out;
        signal(mutex);

        signal(empty);

        //consume the item nextc
    }
}

main() {
    cobegin { producer(), consumer() };
}
```

[**变型**] 对于生产者 - 消费者问题，假设缓冲区是无界的，试给出算法。

由于是无界缓冲区，所以生产者不会因为得不到缓冲区而被阻塞，可以舍去对空缓冲区进行管理的信号量 empty 及其PV操作。

```cpp
int in = 0, out = 0;
item buffer[n];
semaphore mutex = 1;
semaphore full = 0;  //满缓冲区数量

void producer() {
    while(true) {
        //produce an item nextp;

        wait(mutex);
        buffer[in] = nextp;
        in++;
        signal(mutex);

        signal(full);
    }
}

void consumer() {
    while(true) {
        wait (full);

        wait(mutex);
        nextc = buffer[out];
        out++;
        signal(mutex);

        //consume the item nextc
    }
}

main() {
    cobegin { producer(), consumer() };
}
```

* 一个司机和一个售票员的同步算法。

```cpp
semaphore start = 0;
semaphore open = 0;

void driver() {
    while(true) {
        P(start);
        //启动车辆
        //正常行车
        //到站停车
        V(open);
    }
}

void seller() {
    while(1) {
        //关车门
        V(start);
        //售票
        P(open);
        //开车门
    }
}

main() {
    cobegin { driver(), seller() };
}
```

* 桌上有一空盘，最多允许存放一只水果。爸爸可向盘中放一个苹果或放一个桔子，儿子专等吃盘中的桔子，女儿专等吃苹果。试写出爸爸、儿子、女儿三个并发进程的同步算法。

```cpp
semaphore S = 1;  //空盘子数
semaphore So = 0; //盘中橘子数
semaphore Sa = 0; //盘中苹果数

void Father() {
    while(1) {
        wait(S);
        //将水果放入盘中;
        if(是桔子) signal(So);
        else signal(Sa);
     }
}

void Son() {
    while(1) {
        wait(So)
        //取桔子
        signal(S);
        //吃桔子;
   }
}

void Daughter() {
    while(1) {
        wait(Sa)
        //取苹果
        signal(S);
        //吃苹果;
   }
}

main() {
    cobegin {Father(); Son(); Daughter(); };
}
```
