#pragma once
class AbstractHospital
{
public:
    void  work()
    {
        registe();
        seeDoc();
        checkBody();
        verb();
     }

protected:
     /**
    * 挂号
    */
     virtual void registe() = 0;

     /**
      * 看医生
      */
     virtual void seeDoc() = 0;

     /**
      * 各项检查
      */
     virtual void checkBody() = 0;

     /**
      * 治疗
      */
     virtual void verb() = 0;
private:
};

