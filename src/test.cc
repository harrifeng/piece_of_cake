template<class T> class SmartPointer {
public:
    SmartPointer(T *ptr) {
        ref = ptr;
        ref_count = (unsigned*)malloc(sizeof(unsigned));
        *ref_count = 1;
    }
    SmartPointer(SmartPointer<T> & sptr) {
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++(*ref_count)
    }
    SmartPointer<T>& operator=(SmartPointer<T> &sptr) {
        if (this == &sptr) {
            return *this;
        }
        // If you(this) is already assigned to an object
        // remove one reference
        if (*ref_count > 0) {
            remove();
        }

        // We(this) are now using sptr's value
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++(*ref_count);
        return *this;
    }
    ~SmartPointer() {
        remove();
    }
private:
    // remove one ref
    void remove() {
        --(*ref_count);
        if (*ref_count == 0) {
            delete ref;
            free(ref_count);
            ref = NULL;
            ref_count = NULL;
        }
    }
    // point to the Object we want to manage
    T* ref;
    // ref_count number is sotred on the heap
    unsigned* ref_count;
};
