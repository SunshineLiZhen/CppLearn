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
    * �Һ�
    */
     virtual void registe() = 0;

     /**
      * ��ҽ��
      */
     virtual void seeDoc() = 0;

     /**
      * ������
      */
     virtual void checkBody() = 0;

     /**
      * ����
      */
     virtual void verb() = 0;
private:
};

