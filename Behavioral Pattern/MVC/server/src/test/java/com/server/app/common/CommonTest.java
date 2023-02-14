package com.server.app.common;

import com.server.app.exception.ApplicationExceptions;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.microdeaf.hbm.model.BaseEntity;
import lombok.extern.slf4j.Slf4j;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.List;

@Slf4j
public abstract class CommonTest {

    private ObjectMapper mapper = new ObjectMapper();

    protected <T> void write(T value) {
        try {
            log.info(mapper.writeValueAsString(value));
        } catch (JsonProcessingException e) {
            throw new ApplicationExceptions(e);
        }
    }

    protected <T extends BaseEntity> void validateEntity(T entity) {
        if (entity != null) {
            write(entity);
        } else {
            throw new ApplicationExceptions("");
        }
    }

    protected <T extends BaseEntity> void validateEntities(List<T> entities) {
        if (entities != null) {
            write(entities);
        } else {
            throw new ApplicationExceptions("");
        }
    }

    protected <T extends BaseEntity> void validateNewEntity(T entity) {
        if (entity.getId() != null) {
            write(entity);
        } else {
            throw new ApplicationExceptions("");
        }
    }

    protected String getCurrentDate() {
        SimpleDateFormat inputFormat = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        return inputFormat.format(Calendar.getInstance().getTime());
    }

}
