attribute highp vec4 pos;
attribute lowp vec4 col;

varying lowp vec4 color;

uniform mat4 matrix;


void main(void)
{
    gl_Position = matrix * pos;
    color = col;
}
