class Singleton
{
private:
   Singleton();

public:
   static Singleton& instance()
   {
      static Singleton INSTANCE;
      return INSTANCE;
   }
};