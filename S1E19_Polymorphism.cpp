// Полиморфизм.

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

namespace PolymorphismExample {
 
////////////////////////////////////////////////////////////////////////////////////////////////////

// Абстрактная фигура.
// Общий предок для CPoint, CRect, CLine, CCompoundShape
class CFigure {
public:
	int Color = 0;

	CFigure() = default;
	CFigure( int color ) : Color( color ) {}

	virtual ~CFigure() {}

	virtual void Draw( const string& indent = "" ) {
		cout << indent << "Color: " << Color << endl;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class CPoint : public CFigure {
public:
	int X = 0;
	int Y = 0;

	CPoint() = default;
	CPoint( int x, int y ) : X( x ), Y( y ) {}

	virtual void Draw( const string& indent = "" ) {
		cout << indent << "CPoint:" << endl;
		CFigure::Draw( indent + "  " );
		cout << indent << "  X: " << X << endl;
		cout << indent << "  Y: " << Y << endl;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class CRect : public CFigure {
public:
	CPoint TopLeft;
	CPoint BottomRight;

	CRect() = default;
	CRect( int left, int top, int right, int bottom ) : TopLeft( left, top ), BottomRight( right, bottom ) {}

	virtual void Draw( const string& indent = "" ) {
		cout << indent << "CRect:" << endl;
		CFigure::Draw( indent + "  " );
		TopLeft.Draw( indent + "  " );
		BottomRight.Draw( indent + "  " );
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class CLine : public CFigure {
public:
	CPoint Begin;
	CPoint End;

	CLine() = default;
	CLine( const CPoint& begin, const CPoint& end ) : Begin( begin ), End( end ) {}

	virtual void Draw( const string& indent = "" ) {
		cout << indent << "CLine:" << endl;
		CFigure::Draw( indent + "  " );
		Begin.Draw( indent + "  " );
		End.Draw( indent + "  " );
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

// Составная фигура.
class CCompoundShape : public CFigure {
public:
	vector<CFigure*> Children;

	virtual ~CCompoundShape()
	{
		DeleteAll();
	}

	virtual void Draw( const string& indent = "" ) {
		cout << indent << "CCompoundShape:" << endl;
		CFigure::Draw( indent + "  " );
		for( int i = 0; i < static_cast<int>( Children.size() ); i++ ) {
			Children[i]->Draw( indent + "  " );
		}
	}

	void Add( CFigure* child ) {
		Children.push_back( child );
	}

	void DeleteAll() {
		for( int i = 0; i < static_cast<int>( Children.size() ); i++ ) {
			delete Children[i];
		}
		Children.empty();
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace PolymorphismExample

using namespace PolymorphismExample;

// main
int main_Polymorphism()
{
	CFigure* figure = 0;

	CPoint* point = new CPoint();
	point->Color = 10;
	point->X = 20;
	cout << endl;
	point->Draw();

	figure = point;
	figure->Color = 20;
	cout << endl;
	figure->Draw();

	CLine* line = new CLine();

	figure = line;
	cout << endl;
	figure->Draw();

	delete point;
	delete figure;

	CCompoundShape shape;
	shape.Add( new CPoint( 1, 2 ) );
	shape.Add( new CRect( 3, 4, 5, 6 ) );
	shape.Add( new CLine( CPoint( 7, 8 ), CPoint( 9, 10 ) ) );
	cout << endl;
	shape.Draw();

	CFigure& shapeAsFigure = shape;
	cout << endl;
	shapeAsFigure.Draw();

	system( "Pause" );
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
