#include"List.h"
#include"List.cpp"
#include"Student.h"
void ForInt();
void ForStudent();
int main() {
    
    //ForInt();
    ForStudent();
    

    return 0;
    
}
void ForInt() {
    int tmp, indx;
    int arr[] = { 10,100,1,5 };
    List<int> s(arr, 4);
   /* cout << "删除前" << endl;*/
    s.traverse(print);
    s.quick_sort(0, s.Getlen() - 1);//排序
    s.traverse(print);
    /*cout << "删除后" << endl;*/
   /* s.traverse(print);*/
    //s.insertByLoct(3, 7);
    //s.insertByLoct(2, 5);
    //s.traverse(print);
    //if (s.removeByloct(0, tmp))
    //    cout << "按位置删除的元素为：" << tmp << endl;//删除为第0号元素，不存在
    //cout << s.removeByVal(indx, 2) << endl;
    //s.traverse(print);
    //cout << "查找元素的位置" << s.Getindex(2, compare) << endl;
    //if (s.removeByVal(indx, 1)) {
    //    cout << "按照元素删除，该元素下标为：" << indx << endl;
    //    s.traverse(print);
    //}
    /*if (s.updateList(8, 4))
        s.traverse(print);*/
    //s.traverse(print);
    //s.quick_sort(0, s.Getlen() - 1);
    //s.traverse(print);
}
void ForStudent() {
    student s1("xiaoming", "1111");
    student s2("xiaohu", "7777");
    student s3("xiaohei", "5555");
    student s4("awei", "6666");
    student s5("xiaohong", "8888");
    student s6("xiaolong", "2222");
    student s7("xiaohao", "3333");
    student s8("xiaofei", "0000");
    student s9;
    student ss[] = { s1,s2,s3 };
    List<student> l(ss,3);
    l.traverse(print);
    l.quick_sort(0, l.Getlen() - 1);//排序
    l.traverse(print);

    /*l.insertByLoct(2, s4);
    l.insertByLoct(3, s5);
    
    ;*/
    /*l.traverse(print);
    int indx;
    if(l.removeByloct(1, s9))
        cout << "按位置删除的元素为：" << s9 << endl;
    l.traverse(print);
    cout << "查找元素的位置" << l.Getindex(s3, compare) << endl;
    if (l.removeByVal(indx, s7)) {
        cout << "按照元素删除，该元素下标为：" << indx << endl;
        l.traverse(print);
    }
    if (l.updateList(s2, s7))
        l .traverse(print);*/
    //l.quick_sort(0, l.Getlen() - 1);

}

