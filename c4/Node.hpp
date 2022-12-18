//
// Created by martin on 12/18/22.
//

#pragma once

template < typename T >
struct Node;

template < typename T >
struct Node
{
    T info;
    Node *next;
};