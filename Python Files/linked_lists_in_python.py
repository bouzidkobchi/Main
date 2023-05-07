from rich import print 
class node :
    def __init__(self , value , next=None):
        self.value = value
        self.next = next
    def __add__(self,__x) :
        concatenate

def append(head , value) :
    while head.next != None :
        head = head.next
    head.next = node(value)

def length(head) -> int :
    p , length = head , 0
    while p != None :
        length += 1
        p = p.next
    return length

def remove_head(head) :
    for item in globals() :
        if globals()[item] == head : globals()[item] = globals()[item].next 

def remove_item_by_index(head:node, index) :
    if index == 0 : remove_head(head)
    if index > length(head) : return 
    for i in range(0 , index-1):
        head = head.next

    to_delete = head
    to_delete.next = to_delete.next.next
    del to_delete

def add_item_by_index(head:node, index , value) :
    if index == 0 :
        for item in globals() :
            if globals()[item] == head : 
                globals()[item] = node(value,head)
                return

    index -= 1
    if index > length(head) -1 : return
    for i in range(index) :
        head = head.next
    last = head.next
    head.next = node(value)
    head.next.next = last

def show_list(head, title=None):
    if title != None : print(f'{title} : ',end='')
    while head != None :
        print(f'{head.value} -> ',end='')
        head = head.next
    print('/')

def object_by_index(head , index) -> node :
    if index > len(head) -1 : return node('this index does not exist',None)
    for i in range(index) :
        head = head.next
    return head

def object_by_value(head , value) -> node :
    while head != None and head.value != value :
        head = head.next
    if head == None : return node('this value does not exist',None)
    return head

def swap_by_value(head , first , second) :
    ptr = head
    while ptr != None :
        if ptr.value == second : ptr.value = first
        elif ptr.value == first : ptr.value = second
        ptr = ptr.next

def index(head , value):
    indexes = []
    i = 0
    while head != None :
        if head.value == value :
            indexes.append(i)
        i += 1
        head = head.next
    if len(indexes) == 1 : indexes = indexes[0]
    return indexes

def swap_by_index(head , first_index , second_index) : 
    val1 , val2 = value_by_index(head,first_index) , value_by_index(head,second_index)
    while head != None :
        if head.value == val1 : head.value = val2
        elif head.value == val2 : head.value = val1
        head = head.next
        
def to_list(head:node) :
    my_list = []
    while head != None :
        my_list.append(head.value)
        head = head.next
    return my_list

def to_linked_list(my_list:list) :
    for i in range(len(my_list)-1) :
        if i == 0 :
            head = node(my_list[0])
            ptr = head
        head.next = node(my_list[i+1])
        head = head.next
    return ptr

def concatenate(head1 , head2 ) :
    ptr = head1
    while head1.next != None :
        head1 = head1.next
    head1.next = head2
    return ptr

def replace_by_index(head , index , new_value) :
    current_index = 0
    while head != None :
        if current_index == index : head.value = new_value 
        current_index += 1
        head = head.next

def value_by_index(head , index) :
    current_index = 0
    while head.next != None :
        if current_index == index : return head.value
        current_index += 1
        head = head.next 

def remove_last(head) :
    while head.next.next != None :
        head = head.next
    del head.next
    head.next = None

# doesnot work
def reverse(head) :
    ptr = head
    k = node(0)
    l = k
    for i in range(length(head)-1,-1,-1) :
        head = ptr
        for j in range(i) :
            head = head.next
        k.value = head.value
        k.next = node(0)
        k = k.next 
        
    remove_last(l)
    show_list(l)
    
    
    # for i in range(length(head)-1) :
    #     ptr.value = head.value
    #     head = head.next
    #     ptr= ptr.next
    # show_list(k)
 
# def main() :
#     global a
#     a = to_linked_list([])

# if __name__ == '__main__' :
#     main()


a = to_linked_list([*range(10)])
show_list(a,'a')
b = to_linked_list(['bouzid',14.25,0,None,[1,2,3],(4,5,2),{4,5,0}])
# show_list(b,'b')
# print(length(b))
reverse(a)
show_list(a,'a')
