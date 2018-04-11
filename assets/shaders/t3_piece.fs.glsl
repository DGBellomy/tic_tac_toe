#version 330 core

in vec2 TexCoord;

out vec4 frag_color;

uniform sampler2D X_Piece;
uniform sampler2D O_Piece;

void main()
{
    frag_color = texture(X_Piece, TexCoord);
}
