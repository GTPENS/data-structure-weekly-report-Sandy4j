void displayLIFO() {
    Node* temp = tail;
    cout << "Data dalam Double Linked List (LIFO): " << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->name << ", NRP: " << temp->nrp << endl;
        temp = temp->prev;
    }
}

void displayFIFO() {
    Node* temp = head;
    cout << "Data dalam Double Linked List (FIFO): " << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->name << ", NRP: " << temp->nrp << endl;
        temp = temp->next;
    }
}