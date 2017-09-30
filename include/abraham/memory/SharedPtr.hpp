//
// Created by Matthew Remmel on 9/29/17.
//

#ifndef ABRAHAM_SHAREDPTR_HPP
#define ABRAHAM_SHAREDPTR_HPP

#include <memory>


namespace abraham {

    /**
     * A wrapper around std::shared_ptr that provides more convenient and higher level functions.
     * @tparam T - The pointer type of the object to take ownership of by the SharedPtr.
     */
    template<typename T>
    class SharedPtr {
    protected:
        /**
         * The internal std::shared_ptr object that this class wraps.
         */
        std::shared_ptr<T> _data;

    public:
        /**
         * Default constructor that creates an empty SharedPtr.
         */
        SharedPtr();

        /**
         * Constructor to create a SharedPtr for an already existing raw pointer.
         * @param pointer - The raw pointer to manage with SharedPtr.
         */
        explicit SharedPtr(T* pointer);

        /**
         * Constructor to create a SharedPtr from another SharedPtr.
         * @param ptr - The SharedPtr to create this SharedPtr from.
         */
        SharedPtr(const SharedPtr<T>& ptr);

        /**
         * Constructor to create a SharedPtr from a std::shared_ptr.
         * @param ptr - The std::shared_ptr to create this SharedPtr from.
         */
        SharedPtr(const std::shared_ptr<T>& ptr);

        /**
         * Constructor to create a SharedPtr explicitly initialized to null.
         */
        SharedPtr(std::nullptr_t np);

        /**
         * Move constructor.
         * @param ptr - The SharedPtr to move to this SharedPtr.
         */
        SharedPtr(SharedPtr&& ptr) noexcept;

        /**
         * Constructor to create a SharedPtr from a std::shared_ptr by moving.
         * @param ptr - The std::shared_ptr to create this SharedPtr from.
         */
        SharedPtr(std::shared_ptr<T>&& ptr);

        /**
         * Operator overload to set new SharedPtr contents using the '=' operator.
         * @param ptr - The SharedPtr object to set the new contents from.
         * @return A self reference.
         */
        SharedPtr<T>& operator=(const SharedPtr<T>& ptr);

        /**
         * Operator overload to set new SharedPtr contents by moving.
         * @param ptr - The SharedPtr object to set the new contents from.
         * @return A self reference.
         */
        SharedPtr<T>& operator=(SharedPtr<T>&& ptr) noexcept;

        /**
         * Release ownership of any currently held object and set contents to null.
         * @param np - nullptr.
         * @return A self reference.
         */
        SharedPtr<T>& operator=(std::nullptr_t np);

        /**
         * Operator overload to check the equality of two SharedPtr objects using the '==' operator.
         * @param ptr - The SharedPtr object to compare this SharedPtr to.
         * @return true if the SharedPtr objects point to the same object; false otherwise.
         */
        bool operator==(const SharedPtr<T>& ptr) const;

        /**
         * Operator overload to check the inequality of two SharedPtr objects using the '!=' operator.
         * @param ptr - The SharedPtr object to compare this SharedPtr to.
         * @return true if the SharedPtr objects do not point to the same object; false otherwise.
         */
        bool operator!=(const SharedPtr<T>& ptr) const;

        /**
         * A bool conversion to support checking the contents of a SharedPtr using 'if (shared_ptr) ...'
         * @return true if the managed object isn't null; false otherwise.
         */
        explicit operator bool() const noexcept {
            return _data.get() != nullptr;
        }

        /**
         * Operator overload to return a reference to the managed object using the '*' operator.
         * @return A reference to the managed object.
         */
        T& operator*() const;

        /**
         * Operator overload to access the nanaged object using the '->' operator.
         * @return A pointer to the managed object.
         */
        T* operator->() const;

        /**
         * Factory method to create a SharedPtr with a constructed object inside.
         * @param args - Constructor arguments for T. Can be empty.
         * @return A SharedPtr with a newly constructed managed object inside.
         */
        template<typename... Args>
        static SharedPtr<T> make(Args&& ... args);

        /**
         * @return A pointer to the managed object.
         */
        T* get() const;

        /**
         * Release ownership of any currently held object and take ownership of a new object.
         * @param pointer - The new object to manage.
         * @return A self reference.
         */
        SharedPtr<T>& set(T* pointer);

        /**
         * Release ownership of any currently held object and set contents to null.
         * @param np - nullptr.
         * @return A self reference.
         */
        SharedPtr<T>& set(std::nullptr_t np);

        /**
         * Release ownership of any currently held object and set contents to null.
         * @return A self reference.
         */
        SharedPtr<T>& reset();

        /**
         * @return true if there is no currently managed object; false otherwise.
         */
        bool isEmpty() const;

        /**
         * @return The internal std::shared_ptr representation.
         */
        std::shared_ptr<T> std_shared_ptr() const;
    };

    /*
     * Template implementation
     */

    template<typename T>
    SharedPtr<T>::SharedPtr() {
        this->_data = std::shared_ptr<T>();
    }

    template<typename T>
    SharedPtr<T>::SharedPtr(T* pointer) {
        this->_data = std::shared_ptr<T>(pointer);
    }

    template<typename T>
    SharedPtr<T>::SharedPtr(const SharedPtr<T>& ptr) {
        this->_data = ptr._data;
    }

    template<typename T>
    SharedPtr<T>::SharedPtr(const std::shared_ptr<T>& ptr) {
        this->_data = ptr;
    }

    template<typename T>
    SharedPtr<T>::SharedPtr(std::nullptr_t np) {
        this->_data = np;
    }

    template<typename T>
    SharedPtr<T>::SharedPtr(SharedPtr&& ptr) noexcept {
        this->_data = ptr._data;
    }

    template<typename T>
    SharedPtr<T>::SharedPtr(std::shared_ptr<T>&& ptr) {
        this->_data = ptr;
    }

    template<typename T>
    SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& ptr) {
        this->_data = ptr._data;
        return *this;
    }

    template<typename T>
    SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& ptr) noexcept {
        this->_data = ptr._data;
        return *this;
    }

    template<typename T>
    SharedPtr<T>& SharedPtr<T>::operator=(std::nullptr_t np) {
        this->_data = np;
        return *this;
    }

    template<typename T>
    bool SharedPtr<T>::operator==(const SharedPtr<T>& ptr) const {
        return this->_data == ptr._data;
    }

    template<typename T>
    bool SharedPtr<T>::operator!=(const SharedPtr<T>& ptr) const {
        return this->_data != ptr._data;
    }

    template<typename T>
    T& SharedPtr<T>::operator*() const {
        return this->_data.operator*();
    }

    template<typename T>
    T* SharedPtr<T>::operator->() const {
        return this->_data.operator->();
    }

    template<typename T>
    template<typename... Args>
    SharedPtr<T> SharedPtr<T>::make(Args&& ... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    T* SharedPtr<T>::get() const {
        return this->_data.get();
    }

    template<typename T>
    SharedPtr<T>& SharedPtr<T>::set(T* pointer) {
        this->_data.reset(pointer);
        return *this;
    }

    template<typename T>
    SharedPtr<T>& SharedPtr<T>::set(std::nullptr_t np) {
        this->_data.reset();
        return *this;
    }

    template<typename T>
    SharedPtr<T>& SharedPtr<T>::reset() {
        this->_data.reset();
        return *this;
    }

    template<typename T>
    bool SharedPtr<T>::isEmpty() const {
        return this->_data.get() == nullptr;
    }

    template<typename T>
    std::shared_ptr<T> SharedPtr<T>::std_shared_ptr() const {
        return std::shared_ptr<T>(this->_data);
    }
}

#endif //ABRAHAM_SHAREDPTR_HPP
