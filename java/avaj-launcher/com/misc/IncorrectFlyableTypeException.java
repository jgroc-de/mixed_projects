package com.misc;

public class IncorrectFlyableTypeException extends Exception {
    private static final long serialVersionUID = 1L;

    public IncorrectFlyableTypeException(String errorMessage) {
        super(errorMessage);
    }
}