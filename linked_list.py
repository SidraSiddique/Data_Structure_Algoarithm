class Node:
    def __init__(self, val=None):
        self.info = val
        self.next = None
        
class LinkList:
    def __init__(self):
        self.head = None
    def insert_at_head(self, val):
        new_node=Node(val)
        new_node.next=self.head
        self.head=new_node
        
    def insert_at_tail(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def insert_after(self, key, val):
        new_node = Node(val)
        if self.head is None:
            return
        temp = self.head
        while temp is not None:
            if temp.info == key:
                new_node.next = temp.next
                temp.next = new_node
            temp = temp.next

    def insert_before(self, key, val):
        if self.head is None:
            return
        if self.head.info == key:
            new_node = Node(val)
            new_node.next = self.head
            self.head = new_node
            return
        current = self.head
        while current.next and current.next.info != key:
            current = current.next
        if current.next:
            new_node = Node(val)
            new_node.next = current.next
            current.next = new_node

    def search(self, key):
        if self.head is None:
            return 
        temp=self.head
        while temp is not None:
            if temp.info==key:
                return temp
            temp=temp.next

    def update(self,key,val):
        if self.head is None:
            return
        temp=self.head
        while temp is not None:
            if temp.info==key:
                temp.info=val
            temp=temp.next

    def remove_at_head(self):
        if self.head is None:
            return
        temp=self.head
        self.head=temp.next
        del temp
    def remove_at_tail(self):
        if self.head is None:
            return
        if self.head.next is None:
            del self.head
            self.head=None
        temp=self.head
        temp1=self.head
        while temp.next is not None:
            temp1=temp
            temp=temp.next
        temp1.next=None
        del temp
    def remove_after(self, key):
        if self.head is None:
            return
        current = self.head
        while current:
            if current.info == key:
                if current.next:  
                    next_node = current.next
                    current.next = next_node.next
                    del next_node  
            current = current.next
        
        
    def remove_before(self,key):
        if self.head is None:
            return
        if self.head.info == key:
            return
        prev=None
        temp= self.head
        while temp.next:
            if temp.next.info == key:
                if prev:
                    prev.next = temp.next
                else:
                    self.head = temp.next
                    del temp
                return
            prev=temp
            temp = temp.next
    def remove(self,key):
        if self.head is None:
            return
        prev=None
        temp=self.head
        while temp is not None:
            if temp.info==key:
                if prev is None:
                    self.head=temp.next
                else:
                    prev.next=temp.next
            prev=temp
            temp=temp.next
        del temp
    def removekthnode(self,k):
        if self.head is None:
            return
        if k<0:
            return 'Kth node is incorrect'
        prev = None
        temp = self.head
        count = 1
        while temp:
            if count == k:
                if prev is None:
                    self.head = temp.next
                else:
                    prev.next = temp.next
                return  
            prev = temp
            temp = temp.next
            count += 1
        
        del temp

    def shuffle_merge(self,list1,list2):
        temp1=list1.head
        temp2=list2.head
        list3=LinkList()
        cur=None
        while temp1 != None or temp2 != None:
            if temp1:
                new_node=Node(temp1.info)
                if cur:
                    cur.next=new_node
                else:
                    list3.head=new_node
                cur = new_node
                temp1 = temp1.next
            if temp2:
                new_node=Node(temp2.info)
                if cur:
                    cur.next=new_node
                else:
                    list3.head=new_node
                cur= new_node 
                temp2 = temp2.next
        return list3
    def combine(self, list1, list2):
        if not list1.head:
            return list2
        if not list2.head:
            return list1
        tail1 = list1.head
        while tail1.next:
            tail1 = tail1.next
        tail1.next = list2.head
        list2.head = None

        return list1
    def getmiddle(self):
        if self.head is None:
            return
        slow=self.head
        fast=self.head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        return slow
    def singlytocircular(self):
        if self.head is None or self.head.next is None:
            return
        temp=self.head
        while temp.next:
            temp=temp.next
        temp.next=self.head
    def CountNodes(self):
        temp=self.head
        count=0
        while temp is not None:
            count+=1
            temp=temp.next
        print(f'The Nodes present in Singly LinkList is: {count}')

    def Count(self,search_for):
        temp=self.head
        count=0
        while temp!= None:
            if temp.info==search_for:
                count+=1
            temp=temp.next
        print(f'{search_for} is present in List {count} times')
    def checkcircularity(self):
        if self.head is None:
            return
        slow=self.head
        fast=self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                print(f'Circular LinkList')
        print( f'Singly List')
    def reverse(self):
        pass
    def union(self, list1, list2):
        if not list1.head:
            return list2
        if not list2.head:
            return list1
        tail1 = list1.head
        while tail1.next:
            tail1 = tail1.next
        tail1.next = list2.head
        temp = list1.head
        while temp:
            prev = temp
            current = temp.next
            while current:
                if temp.info == current.info:
                    prev.next = current.next
                    del current
                    current = prev.next
                else:
                    prev = current
                    current = current.next
            temp = temp.next
    
        return list1

    def intersection(self, list1, list2):
        temp = list1.head
        while temp:
            temp1 = list2.head
            while temp1:
                if temp.info == temp1.info:
                    print(temp.info, end=' ')
                    break
                temp1 = temp1.next
            temp = temp.next 
    def splitlist(self,position):
        pass
    def addition(self,list1,list2):
        pass
    def findsumpairs(self):
        temp = self.head
        while temp:
            nxt = temp.next
            while nxt and nxt.next:
                if temp.info + nxt.info == nxt.next.info :
                    print(f'The sum pairs are ({temp.info},{nxt.info})')
                elif nxt.next.info+nxt.info==temp.info:
                    print(f'The sum pairs are ({nxt.info},{nxt.next.info})')
                nxt = nxt.next
            temp = temp.next

    def insertvalueinsortedway(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            return
        if val < self.head.info:
            new_node.next = self.head
            self.head = new_node
            return
        temp = self.head
        while temp.next is not None and  temp.next.info < val:
             temp = temp.next
        new_node.next = temp.next
        temp.next = new_node

    def modifylist(self):
        if self.head is None:
            return
        temp=self.head
        while temp != None:
            x=int(input('Enter new value of node:'))
            temp.info=x
            temp=temp.next
    
    def sort(self):
        temp = self.head
        while temp:
            next_node = temp.next
            while next_node:
                if temp.info > next_node.info:
                    temp.info, next_node.info = next_node.info, temp.info
                next_node = next_node.next
            temp = temp.next

    def removeduplicate(self):
        temp = self.head
        while temp:
            prev = None
            temp1 = temp.next
            while temp1:
                if temp.info == temp1.info:
                    if prev is None:
                        self.head = temp1.next
                    else:
                        prev.next = temp1.next
                    del temp1
                    break
                else:
                    prev = temp1
                    temp1 = temp1.next  
            temp = temp.next


    def display(self):
        current = self.head
        while current:
            print(current.info, end=' ')
            current = current.next
        print()

if __name__ == "__main__":
    list1 = LinkList()
    list1.insert_at_head(3)
    list1.insert_at_head(2)
    list1.insert_at_head(1)
    list1.insert_at_tail(4)
    list1.insert_at_tail(6)
    #list1.display()
    #list1.insertvalueinsortedway(5)
    list1.display()
    list1.modifylist()
    list1.display()
    #list1.CountNodes()
    #list1.singlytocircular()
    #list1.getmiddle()
    #list2=LinkList()
    #list2.insert_at_head(4)
    #list2.insert_at_head(5)
    #list2.insert_at_head(23)
    #list2.insert_at_tail(23)
    #list2.insert_at_tail(6)
    #list2.insert_at_tail(78)
    #list2.insert_at_tail(4)
    #list2.insert_at_tail(5)
    #list2.sort()
    #list2.removeduplicate()
    #list2.checkcircularity()
    #list1.union(list1,list2)
    #list1.intersection(list1,list2)
    #list1.findsumpairs()
    #list2.display()
    #list2.Count(2)
    #list1.remove_at_head()
    #list1.remove_at_tail()
    #key_to_search = 3
    #found_node = list1.remove(key_to_search)
    #list1.remove_after(3)
    #list1.remove_before(3)
    #list1.removekthnode(2)
    #print("List 1:")
    #list1.display()
    #print("List 2:")
    #list2.display()
    #list3=list1.combine(list1,list2)
    #print('Combine list:')
    #list3.display()
    #shuffle_merge = list1.shuffle_merge(list1, list2)
    #print("shuffle List:")
    #shuffle_merge.display()
    #print("Original Linked List:")
    #list1.update(2,7)
    #list1.display()
    #list1.insert_after(3, 4)
    #list1.insert_before(2, 6)
    #key_to_search = 4
    #found_node = list1.search(key_to_search)
    #if found_node:
       # print(f"Node with value {key_to_search} found.")
    #else:
        #print(f"Node with value {key_to_search} not found.")
    #print("Linked List after insert_after&before:")
    #list1.display()
    

