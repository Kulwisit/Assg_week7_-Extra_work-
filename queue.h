struct order {
    struct order * next;
    int order_number;
    int type;
    int qty;    
};

typedef struct order Order;

struct queue {
    Order * headPtr, * tailPtr;
    int size;
};
typedef struct queue Queue;

void enqueue_struct(Queue * q, int number, int order_type, int qt);
int dequeue_struct(Queue * q);
void print_queue(Queue q);
void print_bill(int onum, int tnum, int tq);

void enqueue_struct(Queue * q, int number, int order_type, int qt) {
    
    // check if menu does not exist
    if (order_type > 3 || order_type < 1) {
        printf("No Food\n");
        return;
    }

    // setup new order
    Order * new_order = (Order *)malloc(sizeof(Order));
    new_order->order_number = number;
    new_order->type = order_type;
    new_order->qty = qt;
    new_order->next = NULL;

    // add new order into queue
    // create queue
    if (q->size == 0) {
        q->headPtr = new_order;
        q->size++;
    }
    // add node into queue
    else {
        q->tailPtr->next = new_order;
        q->size++;
    }
    // change tailPtr
    q->tailPtr = new_order;

    printf("My order is %d\n", new_order->type);
}

int dequeue_struct(Queue * q) {
    
    Order * temp = q->headPtr;

    // check if queue is empty
    // q is not empty
    if (q->size > 0) {
        // print bill
        print_bill(temp->order_number, temp->type, temp->qty);
        // change head pointer
        q->headPtr = q->headPtr->next;
        q->size--;
    }
    // q is empty
    else {
        printf("the queue is empty\n");
        return -1;
    }

    // free deleted order
    free(temp);

}

void print_queue(Queue q) {
    Order * temp;
    temp = q.headPtr;
    while(q.size > 0) {
        printf("Order: number = %d type = %d qty = %d\n", temp->order_number, temp->type, temp->qty);
        q.size--;
        temp = temp->next;
    }
}

void print_bill(int onum, int tnum, int tq) {

    int input, price;

    printf("Customer no: %d\n", onum);

    switch(tnum) {
        case 1: {
            price = 120*tq;
            printf("Udon\n");
            printf("You have to pay %d\n", price);
            break;
        }
        case 2: {
            price = 80*tq;
            printf("Karage\n");
            printf("You have to pay %d\n", price);
            break;
        }
        case 3: {
            price = 10*tq;
            printf("Tap_water\n");
            printf("You have to pay %d\n", price);
            break;
        }
    }

    printf(":cash:");
    scanf("%d", &input);

    if (input < price) {
        printf("cash:%d\n", price);
    }
    else if (input > price) {
        printf("Thank you\n");
        printf("Change is:%d\n", input-price);
    }
    else {
        printf("Thank you\n");
    }
    
}