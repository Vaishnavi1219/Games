#include "CurvedText"


CurvedText::CurvedText(string str,
	float radius,
	float spacing,
	Font font,
	short charSize)
{
	vertices = VertexArray(PrimitiveType::Quads);
	this->radius = radius;
	spacing = 0;
	this->font = font;
	charSize = 30;
	displayedString = str;
}

void CurvedText::draw(RenderTarget& target, RenderStates states) const
{

	states.transform.combine(Transform::Transform());  //May not work
	if (centered)
		states.transform.combine(centerTransform);
	states.texture = &font.getTexture((unsigned int)charSize);
	target.draw(vertices, states);

}

void CurvedText::UpdateGeometry()
{
	vertices.clear();
	float hspace = font.getGlyph(' ', charSize, true).advance;
	float vspace = font.getLineSpacing(charSize);
	float previousX = 0;
	float x = 0;
	float y = charSize;
	char previousChar = '\0';
	float angleCovered = 0;

	Transform transform = transform.Identity;

	for (char c : displayedString)
	{
		x += font.getKerning(previousChar, c, charSize) + spacing;
		previousChar = c;

		switch (c)
		{
		case ' ':
			x += hspace;
			break;
		case '\t':
			x += 4 * hspace;
			break;
		case '\n':
			y += vspace;
			previousX = 0;
			angleCovered = 0;
			transform = transform.Identity;
			x = 0;
			break;
		case '\v':
			y += vspace * 4;
			break;
		}
		sf::Font font;
		Glyph g = font.getGlyph(c, charSize, false);
		float x0 = x + g.bounds.left;
		float y0 = y + g.bounds.top;
		float x1 = x0 + g.bounds.width;
		float y1 = y0 + g.bounds.height;
		float u0 = g.textureRect.left;
		float v0 = g.textureRect.top;
		float u1 = u0 + g.textureRect.width;
		float v1 = v0 + g.textureRect.height;

		float angle = 2.f * (float)atan((x - previousX) / 2.f / GetRadius())
			* 180.f / (float)M_PI;
		angleCovered += angle;

		transform.rotate(angle, x0 - g.bounds.width / 2.f, GetRadius() / 2.f);

		Vector2f topLeft(x0, y0);
		Vector2f bottomLeft(x0, y1);
		Vector2f topRight(x1, y0);
		Vector2f bottomRight(x1, y1);

		sf::Transform transform;
		transform.transformPoint(x0, y0);
		transform.transformPoint(x1, y0);
		transform.transformPoint(x0, y1);
		transform.transformPoint(x1, y1);

		Vector2f vf1(u0, v0);
		Vertex V(topLeft, color, vf1);
		vertices.append(V);

		Vector2f vf2(u1, v0);
		Vertex v2(topLeft, color, vf1);
		vertices.append(v2);

		Vector2f vf3(u1, v1);
		Vertex v3(topLeft, color, vf1);
		vertices.append(v3);

		Vector2f vf4(u0, v1);
		Vertex v4(topLeft, color, vf1);
		vertices.append(v4);
		/*
		vertices.append(new Vertex(topLeft, color, new Vector2f(u0, v0)));
		vertices.append(new Vertex(topRight, color, new Vector2f(u1, v0)));
		vertices.append(new Vertex(bottomRight, color, new Vector2f(u1, v1)));
		vertices.append(new Vertex(bottomLeft, color, new Vector2f(u0, v1)));*/

		previousX = x;
		x += g.advance;

	}
	centerTransform = transform.Identity;
	centerTransform.rotate(-angleCovered / 2.f, 0, radius);
	centerTransform.translate(0, -radius / 2.f);

}


void CurvedText::SetRadius(float value)
{
	radius = value;
	UpdateGeometry();
}

int CurvedText::GetRadius()
{
	return radius;
}

void CurvedText::SetDisplayedString(string value)
{
	displayedString = value;
	UpdateGeometry();
}

string CurvedText::GetDisplayedString()
{
	return displayedString;
}

void CurvedText::SetCharacterSize(short value)
{
	charSize = value;
	UpdateGeometry();
}

short CurvedText::GetCharacterSize()
{
	return charSize;
}

void CurvedText::SetSpacing(float value)
{
	spacing = value;
	UpdateGeometry();
}

float CurvedText::GetSpacing()
{
	return spacing;
}

void CurvedText::SetFont(Font value)
{
	font = value;
	UpdateGeometry();

}

Font CurvedText::GetFont()
{
	return font;
}

void CurvedText::SetCentered(bool value)
{
	centered = value;
}

bool CurvedText::GetCentered()
{
	return centered;
}

void CurvedText::SetColor(Color value)
{
	color = value;
	for (short i = 0; i < vertices.getVertexCount(); i++)
	{
		Vertex v = vertices[i];
		v.color = color;
		vertices[i] = v;
	}
}

Color CurvedText::GetColor()
{
	return color;
}
