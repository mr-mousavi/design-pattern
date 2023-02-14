package com.server.app.exception;

public class ApplicationExceptions extends RuntimeException {

    public ApplicationExceptions(Exception e) {
        super(e);
    }

    public ApplicationExceptions(String msg) {
        super(msg);
    }
}
