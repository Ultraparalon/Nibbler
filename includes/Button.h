#ifndef BUTTON_H
#define BUTTON_H

#include "Drawable.h"

class Button : public Drawable
{
public:
	Button();
	Button(const int, const int, const int, const int,
		const eTexture);
	~Button();

	bool clicked(const int, const int);

private:

	// bool m_state;
	
};

#endif