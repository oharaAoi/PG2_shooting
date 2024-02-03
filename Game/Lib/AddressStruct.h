#pragma once

struct Address{
	int col;
	int row;
};

struct VertexAddress {
	Address lt;
	Address rt;
	Address lb;
	Address rb;
};

