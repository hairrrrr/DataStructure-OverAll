

class ListNode{
    public int val;
    public ListNode prev;
    public ListNode next;

    public ListNode(int val){
        this.val = val;
    }
}

public class DoubleLinkedList {

    public ListNode head;
    public ListNode last;

    // 头插
    public void addFirst(int data){

        ListNode node = new ListNode(data);

        if(this.head == null){
            this.head = node;
            this.last = node;
        }else {
            node.next = this.head;
            this.head.prev = node;
            this.head = node;
        }
    }

    // 尾插
    public void addLast(int data){

        ListNode node = new ListNode(data);

        if(this.head == null){
            this.head = node;
            this.last = node;
        }else {
            this.last.next = node;
            node.prev = this.last;
            this.last = node;
        }
    }

    //任意位置插入,第一个数据节点为0号下标
    public void addIndex(int index,int data){

        if(this.head == null){
            throw new RuntimeException("链表为空！");
        }

        checkIndex(index);

        if(index == 0){
            addFirst(data);
            return;
        }
        if(index == size()){
            addLast(data);
            return;
        }

        ListNode trg = findIndex(index);

        ListNode node = new ListNode(data);

        node.prev = trg.prev;
        node.next = trg;
        trg.prev.next = node;
        trg.prev = node;

    }

    // 查找是否存在关键字 key
    public boolean contains(int key){

        ListNode cur = this.head;

        while(cur != null && cur.val != key){
            cur = cur.next;
        }

        if(cur == null){
            return false;
        }else{
            return true;
        }

    }


    // 删除第一次出现的关键字 key
    public void remove(int key){

        if(this.head == null){
            throw new RuntimeException("链表为空");
        }

        ListNode cur = this.head;

        while(cur != null){
            if(cur.val == key){
                // 要删除的是头节点
                if(cur == this.head){
                    this.head = this.head.next;
                    this.head.prev = null;

                }else{
                    cur.prev.next = cur.next;
                    if(cur.next == null){
                        this.last = cur.prev;
                    }else{
                        cur.next.prev = cur.prev;
                    }
                }

                return;
            }
            cur = cur.next;
        }

    }


    public void removeAllKey(int key){

        if(this.head == null){
            throw new RuntimeException("链表为空");
        }

        ListNode cur = this.head;

        while(cur != null){
            if(cur.val == key){
                // 要删除的是头节点
                if(cur == this.head){
                    this.head = this.head.next;
                    this.head.prev = null;
                }else{
                    cur.prev.next = cur.next;
                    if(cur.next == null){
                        this.last = cur.prev;
                    }else{
                        cur.next.prev = cur.prev;
                    }
                }
                // 和 remove 函数不同的地方就是这里不return了
            }
            cur = cur.next;
        }
    }

    public void display(){

        ListNode cur = this.head;

        while(cur != null){
            System.out.println(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();
    }

    public void clear(){

        this.head = null;
        this.last = null;
    }

    // 链表长度
    private int size(){

        int lenth = 0;
        ListNode cur = this.head;

        while(cur != null){
            cur = cur.next;
            lenth++;
        }

        return lenth;
    }

    // 确定下标是否合法
    private void checkIndex(int index){

        if(index < 0 || index > size()) {
            throw new ArrayIndexOutOfBoundsException("下标越界！");
        }
    }

    // 寻找下标（确定下标已经存在）
    private ListNode findIndex(int index){

        ListNode cur = this.head;

        while(cur != null && index > 0){
            cur = cur.next;
            index--;
        }

        return cur;
    }
}
