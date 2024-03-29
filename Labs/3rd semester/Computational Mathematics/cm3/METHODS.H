extern double F(double);
/******************************************************************/
/*           �㭪�� F (X) , ���������� ���짮��⥫��             */
/******************************************************************/

#ifdef __NEWTON
extern double F1(double);
/******************************************************************/
/*     �ந������� �㭪樨 F (X) , ���������� ���짮��⥫��       */
/******************************************************************/
#endif

double Round (double X,double Delta);
/******************************************************************/
/*   �㭪�� Round (X,Delta) , �।�����祭� ��� ���㣫����       */
/*                   X � �筮���� Delta                          */
/******************************************************************/

double BISECT(double Left,double Right,double Eps,int &N);
/******************************************************************/
/*    �㭪�� BISECT �।�����祭� ��� �襭�� �ࠢ����� F(X)=0   */
/*    ��⮤�� ������� ��१�� �������. �ᯮ�짮���� ������祭��:  */
/*      Left - ���� ����� �஬���⪠                             */
/*      Right - �ࠢ� ����� �஬���⪠                           */
/*      Eps - ����譮��� ���᫥��� ���� �ࠢ�����;             */
/*      N - �᫮ ���権                                        */
/******************************************************************/

double ITER(double X0,double Eps,int &N);
/******************************************************************/
/*    �㭪�� ITER �।�����祭� ��� �襭�� �ࠢ����� F(X)=X     */
/*      ��⮤�� ���⮩ ���樨. �ᯮ�짮���� ������祭��:       */
/*      X0 - ��砫쭮� �ਡ������� ����                          */
/*      Eps - ����譮��� ���᫥��� ���� �ࠢ�����;             */
/*      N - �᫮ ���権                                        */
/******************************************************************/

double HORDA(double Left,double Right,double Eps,int &N);
/******************************************************************/
/*    �㭪�� HORDA �।�����祭� ��� �襭�� �ࠢ����� F(x)=0    */
/*      ��⮤�� ��. �ᯮ�짮���� ������祭��:                   */
/*      Left - ���� ����� �஬���⪠                             */
/*      Right - �ࠢ� ����� �஬���⪠                           */
/*      Eps - ����譮��� ���᫥��� ���� �ࠢ�����;             */
/*      N - �᫮ ���権                                        */
/******************************************************************/

double NEWTON (double X,double Eps,int &N);
/******************************************************************/
/*  �㭪�� NEWTON �।�����祭� ��� �襭�� �ࠢ����� F(X)=0     */
/*        ��⮤�� ���⥫���. �ᯮ�짮���� ������祭��:          */
/*      X - ��砫쭮� �ਡ������� ����                           */
/*      Eps - ����譮��� ���᫥��� ���� �ࠢ�����;             */
/*      N - �᫮ ���権                                        */
/******************************************************************/

//#include "methods.cpp"
