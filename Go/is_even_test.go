package main

import (
	"fmt"
	"testing"
)

func TestIsEven(t *testing.T) {
	tt := []struct {
		in  int
		out bool
	}{
		{
			in:  1,
			out: false,
		},
		{
			in:  2,
			out: true,
		},
		{
			in:  3,
			out: false,
		},
		{
			in:  10,
			out: true,
		},
		{
			in:  13,
			out: false,
		},
	}

	for _, tc := range tt {
		t.Run(fmt.Sprintf("when the input is %v", tc.in), func(t *testing.T) {
			if r := IsEven(tc.in); r != tc.out {
				t.Errorf("was expecting %v, but returns %v", tc.out, r)
			}
		})
	}
}
