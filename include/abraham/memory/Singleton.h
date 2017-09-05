//
// Created by Matthew Remmel on 9/4/17.
//

#ifndef ABRAHAM_SINGLETON_H
#define ABRAHAM_SINGLETON_H


namespace abraham {

    /**
     * Singleton template to create a single shared instance from any type.
     * @tparam T - The class type to get a shared instance of.
     */
    template<class T>
    class Singleton {
    private:
        /**
         * Disable move constructor.
         */
        Singleton<T>(T&&) = delete;

        /**
         * Disable copy constructor.
         */
        Singleton<T>(const T&) = delete;

        /**
         * Disable assignment.
         */
        Singleton &operator=(T&&) = delete;

        /**
         * Disable assignement.
         */
        Singleton &operator=(const T&) = delete;

    public:
        /**
         * @return A shared instance of the templated type.
         */
        static T &SharedInstance() {
            static T shared;
            return shared;
        }
    };
}

#endif //ABRAHAM_SINGLETON_H
