package com.server.app.exception;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import lombok.Data;

@JsonIgnoreProperties(ignoreUnknown = true)
@Data
public class ResultResource {

    private Integer status;
    private String message;
    private String result;

    public ResultResource(String message, String result, Integer status) {
        this.status = status;
        this.message = message;
        this.result = result;
    }

}
