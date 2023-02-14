package com.server.app.common;

import com.server.app.exception.ApplicationExceptions;
import org.mapstruct.factory.Mappers;
import org.microdeaf.mapper.mapstruct.ApplicationMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.web.client.TestRestTemplate;

import java.io.UnsupportedEncodingException;
import java.net.URI;
import java.net.URLEncoder;

@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT)
public abstract class BaseControllerTest extends BaseServiceTest {

    protected final ApplicationMapper mapper = Mappers.getMapper(ApplicationMapper.class);

    protected abstract String mapperName();

    @Autowired
    protected TestRestTemplate api;

    protected URI uri(String path) {
        return URI.create(path);
    }

    protected String encode(String path) {
        try {
            return URLEncoder.encode(path, "UTF-8");
        } catch (UnsupportedEncodingException e) {
            throw new ApplicationExceptions(e);
        }
    }

}
