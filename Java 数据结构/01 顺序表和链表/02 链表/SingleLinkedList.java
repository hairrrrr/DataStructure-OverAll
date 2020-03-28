

// 无表头单向非循环链表
// 文中所说的表头指的是链表的第一个节点
public class SingleLinkedList {

    public static void main(String[] args) {

        MyLinkedList list = new MyLinkedList();

        list.addLast(3);
        list.addLast(3);
        list.addLast(3);
        list.addIndex(3, 3);
        list.addIndex(3, 3);

        list.display();

        //list.removeAllKey(3);



        list.display();



    }

}
// 定义节点
class Node{
    public int data;
    public Node next;

    public Node(int data){
        this.data = data;
        this.next = null;
    }
}
// 单链表
class MyLinkedList{

    public Node head;

    public MyLinkedList(){
        this.head = null;
    }

    // 头插 复杂度：O(1)
    public void addFirst(int data){

        Node node = new Node(data);

        if(this.head == null){
            this.head = node;
            return;
        }

        node.next = this.head;
        this.head = node;
    }

    // 尾插  复杂度：O(n)
    public void addLast(int data){

        Node node = new Node(data);
        Node cur = this.head;

        if(this.head == null){
            this.head = node;
            return;
        }

        while(cur.next != null){
            cur = cur.next;
        }

        cur.next = node;
    }


    // 在 Index 位置插入   复杂度：O(n)
    public void addIndex(int index, int data){

        Node node = new Node(data);
        Node last = this.head;

        if(index < 0 || index > size()){
            throw new ArrayIndexOutOfBoundsException("数组下标不合法");
        }

        if(index == 0){
            addFirst(data);
            return;
        }

        if(index == size()){
            addLast(data);
            return;
        }

        // 找到要插入的位置的上一个元素
        last = findIndex(index - 1);

        if(last != null) {

            // 将 last 节点的指针域给 node 节点，使得 node 指向 下一个节点
            // 然后将 node 节点的地址 给 last 节点的指针域，使得 last 指向 node
            node.next = last.next;
            last.next = node;
        }else{
            throw new ArrayIndexOutOfBoundsException("数组下标不合法");
        }

    }

    // 删除第一次出现关键字 key 的节点
    public void remove(int key){

        Node lastNode = findNodeBeforeKey(key);
        Node del;

        // 删除表头的情况
        if(this.head.data == key){
            deleteFirst();
            return;
        }

        if(lastNode != null){

            del = lastNode.next;
            lastNode.next = del.next;
            return;
        }

        throw new RuntimeException("链表中没有 key ！");
    }

    // 删除所有值为 key 的节点 复杂度：O(n) （只遍历一次）
    public void removeAllKey(int key){

        // 这是我第一写的
        // 我的思路是 考虑到如果有多个头节点连续删除的特殊情况，先删除头节点，然后再判空
        // 首先 这样写是不对的，可能链表都是 key，删除成空表后，直接访问 data 是非法的
        // 其次，这样写多余了，就算链表是 2 2 2 3 4 （key == 2）这种需要连续删除头节点的情况
        // 我们可以先删除 第一个 2 后面的 所有 2 ，然后再来判断头节点。这样实现，不但代码简单，而且是没有错的。
       /* while(this.head.data == key){
            deleteFirst();
        }

        if(this.head == null) {
            return;
        }*/

       if(this.head == null){
           throw new RuntimeException("链表为空");
       }

        Node last = this.head;
        Node cur = last.next;

        while(cur != null){
            if(cur.data == key){
                last.next = cur.next;
            }else{
                last = last.next;// last = cur;
            }
            cur = cur.next;
        }

        if(this.head.data == key){
            deleteFirst();
        }

    }


    // 删除头节点
    public void deleteFirst(){
        if(this.head == null){
            throw new RuntimeException("删除失败!链表为空");
        }
        this.head = this.head.next;
    }

    // 寻找 data 为 key 的节点的上一个节点
    // 这个函数没有判断 头节点是否为 key 的能力，也就是说你得在其他函数中要考虑到潜在的删除头节点的可能
    // 并且在调用这个函数之前先排除这种可能
    // 换句话说，这个函数的返回值是 null 不代表链表中没有 key
    private Node findNodeBeforeKey(int key){

        Node cur = this.head;

        // 从头节点开始查找每一个节点后面的节点的 data 域
        while(cur.next != null){
            if(cur.next.data == key){
                return cur;
            }
            cur = cur.next;
        }

        return null;
    }


    // 查找链表是否包含关键字 key
    public boolean contain(int key){

        Node cur = this.head;

        while(cur != null){
            if(cur.data == key){
                return true;
            }
            cur = cur.next;
        }

        return false;
    }


    // 寻找下标为 index 的节点
    private Node findIndex(int index){

        Node cur = this.head;

        while(index > 0 && cur != null) {
            cur = cur.next;
            index--;
        }

        return cur;
    }


    // 链表的长度
    public int size(){

        Node cur = this.head;
        int count = 0;

        while(cur != null){
            cur = cur.next;
            count++;
        }

        return count;
    }


    // 打印链表
    public void display(){
        Node cur = this.head;
        while(cur != null){
            System.out.print(cur.data + " ");
            cur = cur.next;
        }

        System.out.println();
    }

    // 销毁链表
    public void clear(){

        // 不被使用的引用会被自动清除，只需要将表头置为 null 即可
        this.head = null;

    }
}