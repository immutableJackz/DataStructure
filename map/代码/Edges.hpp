#include"headAll.h"
#pragma once
class Edges
{
private:
	int from;//��ʼ�� ���
	int to;//�յ� ���
	double wt; //Ȩ��
public:
	Edges() {};
	Edges(int from ,int to,int wt)
		:from(from),to(to),wt(wt){}
	int getTo() { return to; }
	int getFrom() { return from; }
	int getWt() { return wt; }
	void setTo(int to) { this->to = to; }
	void setFrom(int from) {  this->from=from; }
	void setWt(double wt) { this->wt = wt; }
};

