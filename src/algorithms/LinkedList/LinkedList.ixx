module;
#include <memory>
#include <functional>
export module LinkedList;


export namespace CA{

    template<typename T>
    class LinkedListNode {
    private:
        T value;
        std::unique_ptr<LinkedListNode<T>> next;

    public:
        LinkedListNode() = default;

        explicit LinkedListNode(T&& data) : value(std::move(data)), next(nullptr) {}

        explicit LinkedListNode(const T& data): value(data), next(nullptr){};

        LinkedListNode(const LinkedListNode& other) = delete;

        LinkedListNode& operator=(const LinkedListNode& other) = delete;

        LinkedListNode(LinkedListNode&& other) noexcept = default;

        LinkedListNode& operator=(LinkedListNode&& other) noexcept = default;

        ~LinkedListNode() = default;

        T& getData() { return value; }
        const T& getData() const { return value; }

        void setData(const T& data) { value = data; }
        void setData(T&& data) { value = std::move(data); }

        decltype(next)& getNext() { return next; }
        const decltype(next)& getNext() const { return next; }

        void setNext(std::unique_ptr<LinkedListNode<T>> node) {
            next = std::move(node);
        }

        decltype(next) releaseNext() {
            return std::move(next);
        }
    };

    template<typename T>
    class LinkedList {
    private:
        std::unique_ptr<LinkedListNode<T>> head = nullptr;
        std::unique_ptr<LinkedListNode<T>> tail = nullptr;
        size_t size = 0;

    public:
        LinkedList() = default;

        LinkedList(const LinkedList& other) = delete;
        LinkedList& operator=(const LinkedList& other) = delete;

        LinkedList(LinkedList&& other) noexcept = default;
        LinkedList& operator=(LinkedList&& other) noexcept = default;

        ~LinkedList() = default;

        LinkedList& prepend(const T& data);
        LinkedList& prepend(T&& data);

        LinkedList& append(const T& data);
        LinkedList& append(T&& data);

        LinkedList& insert(const T& data, size_t index);
        LinkedList& insert(T&& data, size_t index);

        LinkedList& remove(const T& data);

        template<typename Condition>
        LinkedList& find(Condition&&);
        LinkedList& find(const T& data);

        decltype(tail) deleteTail();
        decltype(head) deleteHead();

        LinkedList& reverse();
    };



}