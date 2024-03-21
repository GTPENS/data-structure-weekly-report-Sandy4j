void insert(string name, int nrp) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->nrp = nrp;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}