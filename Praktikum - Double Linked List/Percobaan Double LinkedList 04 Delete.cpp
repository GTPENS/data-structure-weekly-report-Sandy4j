void deleteNode(string name) {
    Node* temp = searchNode(name);
    if (temp == NULL) {
        cout << "Node dengan nama " << name << " tidak ditemukan." << endl;
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
    }
    else if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node dengan nama " << name << " berhasil dihapus." << endl;
}