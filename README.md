#  OpenGL是CPU和GPU之间通信的桥梁
#  Shader（着色器）运行在GPU上的一段程序

#  VAO(多个VBO存放至一个VAO中，以VAO的形式传送至GPU，从而达到绘制的效果)

#  VBO
#  buffer1, buffer2, buffer3;
#  bind(buffer1);
#  ....
#  bind(buffer2);
#  ....
#  bind(buffer3);
#  ....

# EBO
# 多个VBO由一个EBO统一管理，也就是EBO和VAO是一一对应的
# VBO模式适用于绘制单一三角形，当多边形需要多次绘制三角形时会出现有些边多次
被传入的情况，使用EBO方式，增加index，使之减少传输内容从而提升性能。