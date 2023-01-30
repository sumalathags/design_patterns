template <typename T>
class SmartPointer
{
private:
    T*   object;
    int* refCount;

public:
    SmartPointer(T* object = nullptr)
    {
        this->object = object;
        refCount     = new int(1);
    }

    SmartPointer(const SmartPointer<T>& other)
    {
        object   = other.object;
        refCount = other.refCount;
        (*refCount)++;
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& other)
    {
        if (this != &other)
        {
            if (--(*refCount) == 0)
            {
                delete object;
                delete refCount;
            }
            object   = other.object;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    SmartPointer(SmartPointer<T>&& other) noexcept
    {
        object         = other.object;
        refCount       = other.refCount;
        other.object   = nullptr;
        other.refCount = nullptr;
    }

    SmartPointer<T>& operator=(SmartPointer<T>&& other) noexcept
    {
        if (this != &other)
        {
            if (--(*refCount) == 0)
            {
                delete object;
                delete refCount;
            }
            object         = other.object;
            refCount       = other.refCount;
            other.object   = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    ~SmartPointer()
    {
        if (--(*refCount) == 0)
        {
            delete object;
            delete refCount;
        }
    }

    T* operator->() { return object; }

    T& operator*() { return *object; }
};
