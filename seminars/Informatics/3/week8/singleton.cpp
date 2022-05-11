class Singleton
{
private:
   Singleton();

public:
	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;

   static Singleton& instance()
   {
      static Singleton INSTANCE;
      return INSTANCE;
   }
};