//
// Created by Matthew Remmel on 9/25/17.
//

#ifndef ABRAHAM_UNIQUEPTR_HPP
#define ABRAHAM_UNIQUEPTR_HPP

#include <memory>


namespace abraham {

    /**
     * A wrapper around std::unique_pointer that provides more convenient and higher level functions.
     * @tparam T - The pointer type take ownership of by the UniquePtr.
     */
    template<typename T>
    class UniquePtr {
    protected:
        /**
         * The internal std::unique_ptr object that this class wraps.
         */
        std::unique_ptr<T> _data;

    public:
        /**
         * Default constructor that creates an empty UniquePtr.
         */
        UniquePtr();

        /**
         * Constructor to create a UniquePtr for an already existing raw pointer.
         * @param pointer - The raw pointer to manage with a UniquePtr.
         */
        explicit UniquePtr(T* pointer);

        /**
         * Explicitly deleting copy constructor because UniquePtr cannot be copied.
         */
        UniquePtr(const UniquePtr<T>& ptr) = delete;

        /**
         * Move constructor.
         * @param ptr - The UniquePtr to move to this UniquePtr.
         */
        UniquePtr(UniquePtr<T>&& ptr) noexcept;

        /**
         * Constructor that creates a UniquePtr from a std::unique_ptr.
         * @param ptr - The std::unique_ptr to create this UniquePtr from.
         */
        UniquePtr(std::unique_ptr<T>&& ptr);

        /**
         * Explicitly deleting copy assignment because UniquePtr cannot be copied.
         */
        UniquePtr<T>& operator=(const UniquePtr& ptr) = delete;

        /**
         * Operator overload to set new UniquePointer contents by moving.
         * @param ptr - The UniquePtr object to set the new contents from.
         * @return A self reference.
         */
        UniquePtr<T>& operator=(UniquePtr&& ptr) noexcept;

        /**
         * Release any currently held object and set contents to null.
         * @param np - nullptr.
         * @return A self reference.
         */
        UniquePtr<T>& operator=(std::nullptr_t np);

        /**
         * Operator overload to check the equality of two UniquePtr objects using the '==' operator.
         * @param ptr - The UniquePtr object to compare this UniquePtr to.
         * @return true if the UniquePtr objects point to the same object; false otherwise.
         */
        bool operator==(const UniquePtr<T>& ptr) const;

        /**
         * Operator overload to check the inequality of two UniquePtr objects using the '!=' operator.
         * @param ptr - The UniquePtr object to compare this UniquePtr to.
         * @return true if the UniquePtr objects do not point to the same object; false otherwise.
         */
        bool operator!=(const UniquePtr<T>& ptr) const;

        /**
         * A bool conversion to support checking the contents of UniquePtr using 'if (unique_ptr) ...'
         * @return true if the managed object isn't null; false otherwise.
         */
        explicit operator bool() const noexcept {
            return _data.get() != nullptr;
        };

        /**
         * Operator overload to return a reference to the managed object using the '*' operator.
         * @return A reference to T.
         */
        T& operator*() const;

        /**
         * Operator overload to access the managed object using the '->' operator.
         * @return A pointer to T.
         */
        T* operator->() const;

        /**
         * Factory method to create a UniquePtr with a constructed object inside.
         * @param args - Constructor arguments for T. Can be empty.
         * @return A UniquePtr with the constructed object inside.
         */
        template<typename... Args>
        static UniquePtr<T> make(Args&&... args);

        /**
         * @return A pointer to the managed object.
         */
        T* get() const;

        /**
         * Release any currently held object and take ownership of a new object.
         * @param pointer - The new object to manage.
         * @return A self reference.
         */
        UniquePtr<T>& set(T* pointer);

        /**
         * Release any currently held object and set contents to null.
         * @param np - nullptr.
         * @return A self reference.
         */
        UniquePtr<T>& set(std::nullptr_t np);

        /**
         * Release any currently held object and set contents to null.
         * @return A self reference.
         */
        UniquePtr<T>& reset();

        /**
         * Release ownership of the currently held object and return a pointer to it.
         * @return A pointer to the previously managed object.
         */
        T* release();

        /**
         * @return true if there is no currently managed object; false otherwise.
         */
        bool isEmpty() const;

        /**
         * Downgrade UniquePtr into a std::unique_ptr and return it. This will reset the current UniquePtr.
         * @return A std::unique_ptr that now owns the managed object.
         */
        std::unique_ptr<T> std_unique_ptr();
    };

    /*
     * Template implementation
     */

    template<typename T>
    UniquePtr<T>::UniquePtr() {
        this->_data = std::unique_ptr<T>();
    }

    template<typename T>
    UniquePtr<T>::UniquePtr(T* pointer) {
        this->_data = std::unique_ptr<T>(pointer);
    }

    template<typename T>
    UniquePtr<T>::UniquePtr(UniquePtr<T>&& ptr) noexcept {
        this->_data = std::move(ptr._data);
    }

    template<typename T>
    UniquePtr<T>::UniquePtr(std::unique_ptr<T>&& ptr) {
        this->_data = std::move(ptr);
    }

    template<typename T>
    UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& ptr) noexcept {
        if (this == &ptr) return *this;
        this->_data = ptr._data;
        return *this;
    }

    template<typename T>
    UniquePtr<T>& UniquePtr<T>::operator=(std::nullptr_t np) {
        this->_data = np;
        return *this;
    }

    template<typename T>
    bool UniquePtr<T>::operator==(const UniquePtr<T>& ptr) const {
        return this->_data == ptr._data;
    }

    template<typename T>
    bool UniquePtr<T>::operator!=(const UniquePtr<T>& ptr) const {
        return this->_data != ptr._data;
    }

    template<typename T>
    T& UniquePtr<T>::operator*() const {
        return *(this->_data);
    }

    template<typename T>
    T* UniquePtr<T>::operator->() const {
        return this->_data.operator->();
    }

    template<typename T>
    template<typename... Args>
    UniquePtr<T> UniquePtr<T>::make(Args&&... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    T* UniquePtr<T>::get() const {
        return this->_data.get();
    }

    template<typename T>
    UniquePtr<T>& UniquePtr<T>::set(T* pointer) {
        this->_data.reset(pointer);
        return *this;
    }

    template<typename T>
    UniquePtr<T>& UniquePtr<T>::set(std::nullptr_t np) {
        this->_data.reset(np);
        return *this;
    }

    template<typename T>
    UniquePtr<T>& UniquePtr<T>::reset() {
        this->_data.reset();
        return *this;
    }

    template<typename T>
    T* UniquePtr<T>::release() {
        return this->_data.release();
    }

    template<typename T>
    bool UniquePtr<T>::isEmpty() const {
        return this->_data.get() == nullptr;
    }

    template<typename T>
    std::unique_ptr<T> UniquePtr<T>::std_unique_ptr() {
        T* raw = this->_data.release();
        return std::unique_ptr<T>(raw);
    }
}

#endif //ABRAHAM_UNIQUEPTR_HPP
