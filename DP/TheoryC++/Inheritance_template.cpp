        #include <iostream>

        using namespace std; 

        template<typename T>class clsTemplate

        {

            public:

            T value;

            clsTemplate(T i)

            {

                value = i;

            }

        void test()

        {

            cout << value << endl;

        }

        };

        class clsChild : public clsTemplate<char>

        {

            public:

            clsChild(): clsTemplate<char>( 0 )

            {

            }

            clsChild(char c): clsTemplate<char>( c )

            {    

            }

        void test2()

        {

            test();

        }

        };

        int main()

        {

            clsTemplate <int> a( 42 );

            clsChild b( 'A' );

            a.test();

            b.test2();

            return 0;

        }