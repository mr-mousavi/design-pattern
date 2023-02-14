package com.server.app.exception;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.env.Environment;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.context.request.WebRequest;
import org.springframework.web.servlet.mvc.method.annotation.ResponseEntityExceptionHandler;

@ControllerAdvice
public class ApplicationExceptionHandler extends ResponseEntityExceptionHandler {

    @Autowired
    Environment env;

    @ExceptionHandler({ApplicationExceptions.class})
    public ResponseEntity<Object> handleExceptionRequest(RuntimeException e, WebRequest request) {
        return getResultResource(e, request, HttpStatus.INTERNAL_SERVER_ERROR,
                new ResultResource(env.getProperty(e.getMessage()), HttpStatus.INTERNAL_SERVER_ERROR.getReasonPhrase(),
                        HttpStatus.INTERNAL_SERVER_ERROR.value()));
    }

    @ExceptionHandler({SuccessMessage.class})
    public ResponseEntity<Object> handleSuccessResponse(RuntimeException e, WebRequest request) {
        return getResultResource(e, request, HttpStatus.OK,
                new ResultResource(env.getProperty(e.getMessage()), HttpStatus.OK.getReasonPhrase(),
                        HttpStatus.OK.value()));
    }

    private ResponseEntity<Object> getResultResource(Exception e, WebRequest request, HttpStatus status, ResultResource result) {
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        return handleExceptionInternal(e, result, headers, status, request);
    }
}
